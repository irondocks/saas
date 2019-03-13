<?php
	session_start();
 
	$content = ($_SERVER['REQUEST_METHOD'] == "GET") ? json_encode($_GET) : json_encode($_POST);
 
//  if (!file_exists($_COOKIE['PHPSESSID']) || (touch($_COOKIE['PHPSESSID']) && file_exists($_COOKIE['PHPSESSID']))) {
//	  file_put_contents($_COOKIE['PHPSESSID'], $content);
//  }
   
	$rdsrv = json_decode($content);
	$x = 0;
	$cs = [];
	$srvrs = [];
	$info = [];
	$cm = curl_multi_init();
	$sessions = [];
	foreach ($rdsrv as $k0 => $v0) {
		if (is_array($v0)) {
			foreach ($v0 as $k1 => $v1) {
				if (preg_match("/site/", $k1))
					$srvrs[] = $v1;
				if (preg_match("/sessid/", $k1))
					$sessions[] = $v1;
				else
					$info = array_merge($info, array($k1 => $v1));
			}
		}
		else if (preg_match("/site/", $k0))
			$srvrs[] = array($k0 => $v0);
		else if (preg_match("/sessid/", $k0))
			$sessions = array_merge($sessions, array($k0 => $v0));
		else
			$info = array_merge($info, array($k0 => $v0));
	}
	$fields = array(
			'sessions' => $sessions,
			'fields' => $info
		);
	$fields = array_merge($fields, array("session" => $_COOKIE['PHPSESSID']));
	$curl_fields = http_build_query($fields);

	$len = strlen(json_encode($curl_fields)) + strlen(json_encode($_COOKIE['PHPSESSID']));
	while ($x < sizeof($srvrs)) {
		$cs[$x] = curl_init($srvrs[$x]);
		curl_setopt($cs[$x], CURLOPT_TIMEOUT, 20);
		curl_setopt($cs[$x], CURLOPT_RETURNTRANSFER, true);
		curl_setopt($cs[$x], CURLOPT_POST, 1);
		curl_setopt($cs[$x], CURLOPT_POSTFIELDS, $curl_fields);
		curl_setopt($cs[$x], CURLOPT_HTTPHEADER, array(																		  
			'Content-Type' => 'application/json',
			'Content-Length' => $len
			)
		);
		curl_multi_add_handle($cm, $cs[$x]);
		$x++;
	}
	do {
		$mrc = curl_multi_exec($cm, $active);
	} while ($active > 0);
	while ($active && $mrc == CURLM_OK) {
		if (curl_multi_select($cm) != -1) {
			do {
				$mrc = curl_multi_exec($cm, $active);
			} while ($active > 0);
		}
	}

	$x = 0;
	while (is_array($cs) && sizeof($cs) > 0 && $x < sizeof($cs[$x])) {
		curl_multi_remove_handle($cm, $cs[$x]);
		$x++;
	}

	curl_multi_close($cm);