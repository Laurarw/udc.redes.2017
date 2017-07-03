<?php
if(isset($_POST['email'])) {
 
    $email_to = "impulsocreativoo@gmail.com";
    $email_subject = "Mail de ImpulsoCreativo";
 
    function died($error) {
        
        echo "Lo sentimos mucho, pero hemos encontrado errores en el formulario de contacto enviado. ";
        echo "Esos errores aparecen abajo.<br /><br />";
        echo $error."<br /><br />";
        echo "Por favor regresa al formulario y corrige los errores.<br /><br />";
        die();
    }
 
   
    if(!isset($_POST['nombre']) ||
        !isset($_POST['email']) ||        
        !isset($_POST['mensaje'])) {
        died('Lo sentimos, pero hay problemas con el formulario que has enviado.');       
    }
 
    $nombre = $_POST['nombre']; // requerido
    $email = $_POST['email']; // requerido   
    $comentario = $_POST['mensaje']; // requerido
 
    $error_message = "";
    $email_exp = '/^[A-Za-z0-9._%-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,4}$/';
  if(!preg_match($email_exp,$email)) {
    $error_message .= 'La dirección de email parece inválida.<br />';
  }
    $string_exp = "/^[A-Za-z\s.'-]+$/";
  if(!preg_match($string_exp,$nombre)) {
    $error_message .= 'El nombre no parece válido.<br />';
  }

  if(strlen($comentario) < 2) {
    $error_message .= 'El comentario que has hecho parce no ser válido.<br />';
  }
  if(strlen($error_message) < 0) {
    died($error_message);
  }
    $email_message = "Detalles del formulario debajo.\n\n";
 
    function clean_string($string) {
      $bad = array("content-type","bcc:","to:","cc:","href");
      return str_replace($bad,"",$string);
    }
 
    $email_message .= "Nombre: ".clean_string($nombre)."\n";
    $email_message .= "Email: ".clean_string($email)."\n";   
    $email_message .= "Comentario: ".clean_string($comentario)."\n";
 

$headers = 'De: '.$email."\r\n".
'Reply-To: '.$email."\r\n" .
'X-Mailer: PHP/' . phpversion();
@mail($email_to, $email_subject, $email_message, $headers);
sleep(2);
echo "<meta http-equiv='refresh' content=\"0; url=http://www.impulsocreativo.com.ar/index.html\">"; //agregar la página index
?>
 
<?php
}
?>