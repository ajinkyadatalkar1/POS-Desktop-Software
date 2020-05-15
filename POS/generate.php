<?php

require "vendor/autoload.php";

/*if (!$_GET['text']) {
    header("location: index.php");
    die();
}*/

if($_GET["text"] != "") {
$Bar = new Picqer\Barcode\BarcodeGeneratorHTML();
$code = $Bar->getBarcode($_GET['text'], $Bar::TYPE_CODE_128);

$generator = new \Picqer\Barcode\BarcodeGeneratorPNG();
echo '<img src="data:image/png;base64,' . base64_encode($generator->getBarcode('081231723897', $generator::TYPE_CODE_128)) . '">';
}
?>

