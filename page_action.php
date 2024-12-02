<?php

/*
 * Tento zdrojový kód pochází z WWW.ITNETWORK.CZ
 */

mb_internal_encoding("UTF-8");

$hlaska = '';
if ($_POST) { // V poli _POST něco je, odeslal se formulář
	if (
		isset($_POST['name']) && $_POST['name'] &&
		isset($_POST['mail']) && $_POST['mail'] &&
		isset($_POST['reason']) && $_POST['reason']
	) {
		$hlavicka = 'From:' . $_POST['mail'];
		$hlavicka .= "\nMIME-Version: 1.0\n";
		$hlavicka .= "Content-Type: text/html; charset=\"utf-8\"\n";
		$adresa = 'beranekv@gchd.cz';
		$predmet = 'Nová zpráva z mailformu';
		$uspech = mb_send_mail($adresa, $predmet, $_POST['reason'], $hlavicka);
		if ($uspech) {
			$hlaska = 'Email byl úspěšně odeslán, brzy vám odpovíme.';
		} else
			$hlaska = 'Email se nepodařilo odeslat. Zkontrolujte adresu.';
	} else
		$hlaska = 'Formulář není správně vyplněný!';
}

?>

<!DOCTYPE html>
<html lang="cs">

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<title>Kontaktní formulář</title>
</head>

<body>
	<p>Můžete mě kontaktovat pomocí formuláře níže.</p>

	<?php
	if ($hlaska)
		echo ('<p>' . $hlaska . '</p>');
	?>

	<form action="page_action.php">
        <label><u><b>Blame me</b></u></label>
        <br>
        <label for="name">Your name:</label>
        <br>
        <input type="text" id="name" name="name">
        <br>
        <label for="mail">Your e-mail:</label>
        <br>
        <input type="email" id="mail" name="mail">
        <br>
        <label for="reason">What do you not like about my website?</label>
        <br>
        <textarea id="reason" name="reason" rows="4" cols="50"></textarea>
        <br>
        <input type="submit" value="Submit">
    </form>

</body>

</html>