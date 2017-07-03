<?php
  session_start();
?>

<!DOCTYPE html>
<html lang="es">
<head>

<!-- título de la página -->
<title>ImpulsoCreativo</title>

<!-- tema css --> 
<link href="assets/css/structure.css" rel="stylesheet" type="text/css" />
<link href="assets/css/style.css" rel="stylesheet" type="text/css" />
<link href="assets/css/responsive.css" rel="stylesheet" type="text/css" />
<link href="assets/css/animate.css" rel="stylesheet" type="text/css" />
<script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
<script src="https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js"></script>
 <script type="text/javascript" src="assets/js/bootstrap.min.js"></script>
<!-- carousel css -->
<link href="assets/js/lib/owl-carousel/owl.carousel.css" rel="stylesheet">

<!-- author -->
<meta name="author" content="Lucid Themes">
<script type="text/javascript" src="assets/js/html5.js"></script>
<script type="text/javascript" src="assets/js/encuesta.js"></script>
<!-- responsive meta tag -->
<meta name="viewport" content="width=device-width, initial-scale=1.0" />
<meta charset="UTF-8">

<!-- google fonts usadas -->
<link href='https://fonts.googleapis.com/css?family=Lato:400,300' rel='stylesheet' type='text/css'>
<link href='https://fonts.googleapis.com/css?family=Open+Sans' rel='stylesheet' type='text/css'>

</head>


<body>

<div id="fb-root"></div>
<script>(function(d, s, id) {
  var js, fjs = d.getElementsByTagName(s)[0];
  if (d.getElementById(id)) return;
  js = d.createElement(s); js.id = id;
  js.src = "//connect.facebook.net/es_LA/sdk.js#xfbml=1&version=v2.8";
  fjs.parentNode.insertBefore(js, fjs);
}(document, 'script', 'facebook-jssdk'));</script>

<!-- header -->
<header>
	
	<div class="header-main clearfix edge-padding header-narrow">
		<div class="header-main-inside">
			<div class="container clearfix">
			
				<div class="medium-header-container">
					<!-- logo -->
					<a href="index.html" id="site-logo"><img style="height: 30px" src="../ImpulsoCreativo/assets/img/logo2.png"></a>
					
					<!-- mobile -->
					<div id="mobile-nav-button">
						<div id="mobile-nav-icon">
							<span></span>
							<span></span>
							<span></span>
							<span></span>
						</div>
					</div>
				</div>
				
				<!-- menu -->
				<nav id="header-nav">
				
					<ul id="nav-ul" class="menu font-reg clearfix">
						
						<!-- Nav item -->
						<li class="menu-item menu-item-has-children">
							<a href="index.html">Inicio<span class="sub-drop-icon fa fa-angle-down"></span></a>
						</li>
						<!-- Nav item - con un dropdown -->
						<li class="menu-item menu-item-has-children">
							<a href="">Categorías<span class="sub-drop-icon fa fa-angle-down"></span></a>
							<ul class="sub-menu sub-menu-first">
								<li class="menu-item menu-item-has-children">
									<a>De interés<span class="sub-drop-icon sub-second-drop fa fa-angle-down"></span></a>
									<ul class="sub-menu sub-second-tier">
										<li><a href="tecnologia.html">Tecnología</a></li>
										<li><a href="resource.html">resource</a></li>
										<li><a href="encuestas.html">Encuestas</a></li>
									</ul>
								</li>
								<li><a href="diseno-grafico.html">Diseño gráfico</a></li>
								<li><a href="diseno-web.html">Diseño web</a></li>
								<li><a href="fotografia.html">Fotografía</a></li>
								<li><a href="publicidad.html">Publicidad</a></li>
								<li><a href="tipografia.html">Tipografía</a></li>
								<li><a href="video.html">Video</a></li>
							</ul>
						</li>
						
						<!-- Nav item -->
						<li class="menu-item menu-item-has-children">
							<a href="nosotros.html">Nosotros<span class="sub-drop-icon fa fa-angle-down"></span></a>
						</li>
						
						
						
						<!-- Nav item -->
						<li class="menu-item menu-item-has-children">
							<a href="contacto.html">Contacto<span class="sub-drop-icon fa fa-angle-down"></span></a>
						</li>
						
					</ul>
				
				</nav>
			</div>
		</div>
	</div>
	
</header>


<div id="main-content" class="edge-padding">
	
	<!-- page content -->
	<div class="page-section single-blog">
		<section class="single-blog-main">
			<div class="container">
				
				<div class="row">
				
					<div class="col-xlarge-8 col-medium-8">
					
						<!-- post image -->
						<img src="assets/img/creatividad.jpg" alt="" class="single-image image" />
						
						<!-- post title -->
						<div class="single-blog-title">
							<h2 class="font-reg">Test ¿eres creativo?</h2>
							<p class="font-reg">Por Dra. Vanesa Fernández López, Psicóloga, especialista en emociones.</p>
							<HR width=20% align="left">
						</div>
						
						<!-- post content -->
						<div class="page-content single-blog-content">
							<p>La creatividad permite innovar y encontrar soluciones distintas a los mismos problemas. Si quieres saber si eres creativo, o prefieres no cambiar un entorno conocido y predecible por algo novedoso, contesta el test.</p>
							<p>Dicen que en la variedad está el gusto, y eso es lo que tiene la <strong>creatividad</strong> o capacidad de generar nuevas ideas, que permite innovar y encontrar soluciones distintas aunque se trate de los mismos problemas.</p>
							<p>Algunas personas nacen con esta capacidad muy desarrollada –es el caso de los niños que, ya desde muy pequeños, muestran una imaginación desbordante y son muy ocurrentes–, pero también existe la posibilidad de mejorarla con la educación y con la práctica.</p>
							<p>Aunque la creatividad se considera una cualidad, y más en los tiempos que corren, puede que tú seas de los que se encuentran muy a gusto en un entorno conocido y predecible, y no desees arriesgarte a ensayar cosas nuevas.</p>
                            <p>Si quieres averiguar si eres creativo, o los cambios te <em>marean</em> y prefieres continuar con tus costumbres, responde a las preguntas del test y consulta los resultados asociados a tus respuestas:</p>
						</div>

						<!-- comienzo del formulario de la encuesta -->
					      <div class="page-content single-blog-content">
					        <form name="form_encuesta" action="resultado.php" method="post" id="encuesta" onsubmit=" return validar_encuesta(document.form_encuesta)">
					          
					          <ul>
					          <li><strong>Cuando me hablan sobre algún tema del que no había oído hablar anteriormente</strong>
					            <div>
					              <input type="radio" name="primera" id="preg-1-resp-A" value="A" />
					              <label for="preg-1-resp-A"> No despierta mi interés. </label>
					            </div>

					            <div>
					              <input type="radio" name="primera" id="preg-1-resp-B" value="B" />
					              <label for="preg-1-resp-B"> Siento mucha curiosidad y quiero conocer más sobre él. </label>
					            </div>

					            <div>
					              <input type="radio" name="primera" id="preg-1-resp-C" value="C" />
					              <label for="preg-1-resp-C"> Me puede resultar interesante. </label>
					            </div>
					          </li>

					          <li><strong>Cuando tengo que tomar una decisión o resolver un problema</strong>
					            <div>
					              <input type="radio" name="segunda" id="preg-2-resp-A" value="A" />
					              <label for="preg-2-resp-A">a) Se me ocurren ideas novedosas y únicas. </label>
					            </div>

					            <div>
					              <input type="radio" name="segunda" id="preg-2-resp-B" value="B" />
					              <label for="preg-2-resp-B">b) Elijo la opción que anteriormente ya me resultó más beneficiosa. </label>
					            </div>

					            <div>
					              <input type="radio" name="segunda" id="preg-2-resp-C" value="C" />
					              <label for="preg-2-resp-C">c) Propongo alguna alternativa distinta a lo habitual. </label>
					            </div>
					          </li>

					          <li><strong>Las cosas deben hacerse</strong>
					            <div>
					              <input type="radio" name="tercera" id="preg-3-resp-A" value="A" />
					              <label for="preg-3-resp-A">a) Siempre de la misma manera. </label>
					            </div>

					            <div>
					              <input type="radio" name="tercera" id="preg-3-resp-B" value="B" />
					              <label for="preg-3-resp-B">b) Siguiendo unas pautas generales. </label>
					            </div>

					            <div>
					              <input type="radio" name="tercera" id="preg-3-resp-C" value="C" />
					              <label for="preg-3-resp-C">c) Adaptándose a las nuevas circunstancias y perspectivas. </label>
					            </div>
					          </li>

					          <li><strong>Mi capacidad para encontrar relaciones entre diferentes áreas de conocimiento</strong>
					            <div>
					              <input type="radio" name="cuarta" id="preg-4-resp-A" value="A" />
					              <label for="preg-4-resp-A">a) Es nula. </label>
					            </div>

					            <div>
					              <input type="radio" name="cuarta" id="preg-4-resp-B" value="B" />
					              <label for="preg-4-resp-B">b) Es muy elevada. </label>
					            </div>

					            <div>
					              <input type="radio" name="cuarta" id="preg-4-resp-C" value="C" />
					              <label for="preg-4-resp-C">c) Es bastante mediocre. </label>
					            </div>

					          </li>
					          <li><strong>Cuando alguien me plantea elaborar un proyecto nuevo</strong>
					            <div>
					              <input type="radio" name="quinta" id="preg-5-resp-A" value="A" />
					              <label for="preg-5-resp-A">a) Necesito pensar mucho sobre ello para saber qué quiere exactamente. </label>
					            </div>

					            <div>
					              <input type="radio" name="quinta" id="preg-5-resp-B" value="B" />
					              <label for="preg-5-resp-B">b) Capto inmediatamente la idea y se me ocurren muchas opciones. </label>
					            </div>

					            <div>
					              <input type="radio" name="quinta" id="preg-5-resp-C" value="C" />
					              <label for="preg-5-resp-C">c) Tengo ligeras nociones acerca de cómo empezar a elaborarlo. </label>
					            </div>

					          </li>
					          <li><strong>A la hora de vestirme</strong>
					            <div>
					              <input type="radio" name="sexta" id="preg-6-resp-A" value="A" />
					              <label for="preg-6-resp-A">a) Mi estilo es básico y voy siempre igual. </label>
					            </div>

					            <div>
					              <input type="radio" name="sexta" id="preg-6-resp-B" value="B" />
					              <label for="preg-6-resp-B">b) Mi estilo es bastante normal, pero intento incluir algún complemento que rompa con el aburrimiento. </label>
					            </div>

					            <div>
					              <input type="radio" name="sexta" id="preg-6-resp-C" value="C" />
					              <label for="preg-6-resp-C">c) Me gusta vestir ropa original. </label>
					            </div>
					          </li>

					          <li><strong>Mi imaginación</strong>
					            <div>
					              <input type="radio" name="septima" id="preg-7-resp-A" value="A" />
					              <label for="preg-7-resp-A">a) Es muy rica, y está presente en casi todos los aspectos de mi vida. </label>
					            </div>

					            <div>
					              <input type="radio" name="septima" id="preg-7-resp-B" value="B" />
					              <label for="preg-7-resp-B">b) Es moderada. </label>
					            </div>

					            <div>
					              <input type="radio" name="septima" id="preg-7-resp-C" value="C" />
					              <label for="preg-7-resp-C">c) Brilla por su ausencia. </label>
					            </div>
					          </li>

					          <li><strong>Cuando debo comprar un regalo</strong>
					            <div>
					              <input type="radio" name="octava" id="preg-8-resp-A" value="A" />
					              <label for="preg-8-resp-A">a) No se me ocurre nada, por lo que habitualmente pregunto. </label>
					            </div>

					            <div>
					              <input type="radio" name="octava" id="preg-8-resp-B" value="B" />
					              <label for="preg-8-resp-B">b) Si puedo, intento variar para sorprender. </label>
					            </div>

					            <div>
					              <input type="radio" name="octava" id="preg-8-resp-C" value="C" />
					              <label for="preg-8-resp-C">c) Varío mucho, y se me ocurren regalos completamente inesperados. </label>
					            </div>
					          </li>

					          <li><strong>En cuánto a la decoración de mi hogar</strong>
					             <div>
					              <input type="radio" name="novena" id="preg-9-resp-A" value="A" />
					              <label for="preg-9-resp-A">a) Es bastante sencilla y copio de alguna revista para darle mi toque personal. </label>
					            </div>

					            <div>
					              <input type="radio" name="novena" id="preg-9-resp-B" value="B" />
					              <label for="preg-9-resp-B">b) Suelo ser bastante funcional. </label>
					            </div>

					            <div>
					              <input type="radio" name="novena" id="preg-9-resp-C" value="C" />
					              <label for="preg-9-resp-C">c) Es bastante original, y refleja diferentes aspectos de mi forma de ser. </label>
					            </div>
					          </li>

					          <li><strong>Cuando me dan la responsabilidad de crear un trabajo nuevo</strong>
					            <div>
					              <input type="radio" name="decima" id="preg-10-resp-A" value="A" />
					              <label for="preg-10-resp-A">a) Disfruto creando. </label>
					            </div>

					            <div>
					              <input type="radio" name="decima" id="preg-10-resp-B" value="B" />
					              <label for="preg-10-resp-B">b) Intento meter alguna cosilla de invención propia. </label>
					            </div>

					            <div>
					              <input type="radio" name="decima" id="preg-10-resp-C" value="C" />
					              <label for="preg-10-resp-C">c) Copio lo que ya existía de otro similar. </label>
					            </div>
					          </li>

					          <li><strong>Cuando invito a alguien a cenar</strong>
					            <div>
					              <input type="radio" name="decima_primera" id="preg-11-resp-A" value="A" />
					              <label for="preg-11-resp-A">a) Voy a lo seguro y que sé que les gusta. </label>
					            </div>

					            <div>
					              <input type="radio" name="decima_primera" id="preg-11-resp-B" value="B" />
					              <label for="preg-11-resp-B">b) Acaban sorprendidos por la originalidad de la comida y los detalles que he preparado. </label>
					            </div>

					            <div>
					              <input type="radio" name="decima_primera" id="preg-11-resp-C" value="C" />
					              <label for="preg-11-resp-C">c) Intento hacer cosas nuevas, aunque admito que tengo poca variedad. </label>
					            </div>
					          </li>

					          <li><strong>Los convencionalismos</strong>
					            <div>
					              <input type="radio" name="decima_segunda" id="preg-11-resp-A" value="A" />
					              <label for="preg-11-resp-A">a) Me aterran. </label>
					            </div>

					            <div>
					              <input type="radio" name="decima_segunda" id="preg-11-resp-B" value="B" />
					              <label for="preg-11-resp-B">b) Me tranquilizan. </label>
					            </div>

					            <div>
					              <input type="radio" name="decima_segunda" id="preg-11-resp-C" value="C" />
					              <label for="preg-11-resp-C">c) Me orientan. </label>
					            </div>
					          </li>

					        </ul><br>
					        <input type="submit" name="enviar" value="Respuesta" class="primary-button font-reg hov-bk">
					        </form>

					      </div>

					      <!-- final del formulario de la encuesta-->
					      
						
						<!-- post share -->
						<div id="post-share" class="small-social clearfix">
							<a href="https://www.facebook.com/Impulso-Creativo-1833351386943082/" class="social-item hov-bk" target="_blank" data-popup="facebook"><span class="fa fa-facebook"></span></a>
							<a href="https://twitter.com/impulsocreativ0" class="social-item hov-bk" target="_blank" data-popup="twitter"><span class="fa fa-twitter"></span></a>
						</div>
											
						<!-- Comentarios de Facebook -->
						<div class="post-comments-area font-reg">
							<div id="comments" class="comments-area">						
								<div class="fb-comments" data-href="https://www.impulsocreativo.com.ar" data-width="750" data-numposts="5"></div>
							</div>
						</div>
						
					</div>
					
					
					<!-- destacados -->
					<div class="col-xlarge-4 col-medium-4 post-sidebar right-sidebar">
						
						<!-- posts widget example -->
						<div class="sidebar-widget posts-widget">
							<h3 class="font-reg">Las destacadas</h3>
							<ul>
							
								<li>
									<a href="../ImpulsoCreativo/noticias-impresora.html">
										<div class="row">
											<div class="col-xlarge-5 col-medium-4 col-small-5">
												<img src="assets/img/impresora.jpg" alt="" class="image" />
											</div>
											<div class="col-xlarge-7 col-medium-8 col-small-7">
												<h4 class="font-reg">Impresoras 3D</h4>
												<p>Un negocio para darle vida a tus ideas</p>
											</div>
										</div>
									</a>
								</li>
								
								<li>
									<a href="../ImpulsoCreativo/noticias-responsive.html">
										<div class="row">
											<div class="col-xlarge-5 col-medium-4 col-small-5">
												<img src="assets/img/responsive.jpg" alt="" class="image" />
											</div>
											<div class="col-xlarge-7 col-medium-8 col-small-7">
												<h4 class="font-reg">Responsive o Adaptable</h4>
												<p>La técnica más actual para el diseño y desarrollo de webs</p>
											</div>
										</div>
									</a>
								</li>
								
								<li>
									<a href="../ImpulsoCreativo/noticias-realidad-virtual.html">
										<div class="row">
											<div class="col-xlarge-5 col-medium-4 col-small-5">
												<img src="assets/img/realidad-virtual.jpg" alt="" class="image" />
											</div>
											<div class="col-xlarge-7 col-medium-8 col-small-7">
												<h4 class="font-reg">Tilt Brush</h4>
												<p>Google muestra cómo es pintar en 3D con Realidad Virtual</p>
											</div>
										</div>
									</a>
								</li>
								
							</ul>
						</div>
						
						<!-- lista -->
						<div class="sidebar-widget list-widget">
							<h3 class="font-reg">Categorías</h3>
							<ul class="font-reg">
								<li><a>De interés</a></li>						
								<li><a href="tecnologia.html">&nbsp&nbsp&nbsp• Tecnología</a></li>
								<li><a href="resource.html">&nbsp&nbsp&nbsp• resource</a></li>
								<li><a href="encuestas.html">&nbsp&nbsp&nbsp• Encuestas</a></li>
								<li><a href="diseno-grafico.html">Diseño gráfico</a></li>
								<li><a href="diseno-web.html">Diseño web</a></li>
								<li><a href="fotografia.html">Fotografía</a></li>
								<li><a href="publicidad.html">Publicidad</a></li>
								<li><a href="tipografia.html">Tipografía</a></li>
								<li><a href="video.html">Video</a></li>
							</ul>
						</div>
						
						<!-- social widget -->
						<div class="sidebar-widget social-widget">
							<h3 class="font-reg">Seguinos</h3>
							<ul>
								<div class="fb-follow" data-href="https://www.facebook.com/Impulso-Creativo-1833351386943082" data-layout="button" data-size="small" data-show-faces="true"></div> <br><br>
								<a href="https://twitter.com/ImpulsoCreativ0" class="twitter-follow-button" data-show-count="false" data-lang="es" data-show-screen-name="false">Seguir a @ImpulsoCreativ0</a> <script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?'http':'https';if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src=p+'://platform.twitter.com/widgets.js';fjs.parentNode.insertBefore(js,fjs);}}(document, 'script', 'twitter-wjs');</script>
							</ul>
						</div>
						
						<!-- search widget -->
						<div class="sidebar-widget list-widget">
							<h3 class="font-reg">Buscador</h3>
							<!-- buscador de google -->
					        <script>
							  (function() {
							    var cx = '000883872800647078116:e-dmk3kwav0';
							    var gcse = document.createElement('script');
							    gcse.type = 'text/javascript';
							    gcse.async = true;
							    gcse.src = 'https://cse.google.com/cse.js?cx=' + cx;
							    var s = document.getElementsByTagName('script')[0];
							    s.parentNode.insertBefore(gcse, s);
							  })();
							</script>
							<gcse:search></gcse:search>
						</div>			
						
					</div>
				
				</div>
				
			</div>
			
		</section>
	</div>

</div>


<!-- footer -->
<footer>

	<div class="footer-main edge-padding">
		<div class="footer-main-inside">
			<div class="container clearfix">
			
				<!-- footer contenido -->
				<div class="footer-top">
					<div class="row">
					
						<!-- footer texto -->
						<div class="col-xlarge-4 col-medium-12">
							<div class="footer-about-section">
								<h4 class="font-reg">Lo que nos impulsa</h4>
								<div class="page-content">
									<p>Una sobredosis creativa para que te puedas inspirar en diferentes temas.</p>
								</div>
							</div>
						</div>
						
						<!-- footer interesante columna 1-->
						<div class="col-xlarge-4 col-medium-6">
							<div class="footer-posts-section">
								<h4 class="font-reg">Interesante</h4>
								<div class="posts-widget">
									<ul>
									
										<!-- item 1 -->
										<li>
											<a href="../ImpulsoCreativo/noticias-reflections.html">
												<div class="row">
													<div class="col-xlarge-5 col-medium-4 col-small-5">
														<img src="assets/img/reflexions.jpg" alt="" class="image" />
													</div>
													<div class="col-xlarge-7 col-medium-8 col-small-7">
														<h4 class="font-reg">Campaña de Novartis</h4>
														<p>Recordar con Alzheimer</p>
													</div>
												</div>
											</a>
										</li>
										
										<!-- item 2 -->
										<li>
											<a href="../ImpulsoCreativo/noticias-pantone.html">
												<div class="row">
													<div class="col-xlarge-5 col-medium-4 col-small-5">
														<img src="assets/img/pantone.jpg" alt="" class="image" />
													</div>
													<div class="col-xlarge-7 col-medium-8 col-small-7">
														<h4 class="font-reg">Pantone Greenery</h4>
														<p>El color del 2017</p>
													</div>
												</div>
											</a>
										</li>
										
									</ul>
								</div>
							</div>
						</div>
						
						<!-- footer interesante columna 2 -->
						<div class="col-xlarge-4 col-medium-6">
							<div class="footer-posts-section">
								<h4 class="font-reg">&nbsp</h4>
								<div class="posts-widget">
									<ul>
									
										<!-- item 3 -->
										<li>
											<a href="../ImpulsoCreativo/noticias-hand-drawing.html">
												<div class="row">
													<div class="col-xlarge-5 col-medium-4 col-small-5">
														<img src="assets/img/hand-drawing.jpg" alt="" class="image" />
													</div>
													<div class="col-xlarge-7 col-medium-8 col-small-7">
														<h4 class="font-reg">Hand Drawing</h4>
														<p>Una tendencia de diseño 2017</p>
													</div>
												</div>
											</a>
										</li>
										
										<!-- item 4 -->
										<li>
											<a href="../ImpulsoCreativo/noticias-objetivo.html">
												<div class="row">
													<div class="col-xlarge-5 col-medium-4 col-small-5">
														<img src="assets/img/objetivo.jpg" alt="" class="image" />
													</div>
													<div class="col-xlarge-7 col-medium-8 col-small-7">
														<h4 class="font-reg">50mm F/1.4</h4>
														<p>El rey de los objetivos</p>
													</div>
												</div>
											</a>
										</li>
										
									</ul>
								</div>
							</div>
						</div>
					
					</div>
				</div>
				
				<!-- footer boton contenido -->
				<div class="footer-bottom clearfix">
				
					<!-- footer copyright  -->
					<p class="font-reg">© 2016 ImpulsoCreativo.</p>
					
					<!-- footer social -->
					<ul class="footer-social">
						<li><a href="https://www.facebook.com/Impulso-Creativo-1833351386943082/" target="_blank"><i class="fa fa-facebook"></i></a></li>
						<li><a href="https://twitter.com/impulsocreativ0" target="_blank"><i class="fa fa-twitter"></i></a></li>
					</ul>
					
					<!-- scroll para arriba-->
					<div id="scroll-top">
						<span class="fa fa-angle-up"></span>
					</div>
				
				</div>
				
			</div>
		</div>
	</div>
</footer>




<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/2.0.0/jquery.min.js"></script>
<script type="text/javascript" src="assets/js/lib/owl-carousel/owl.carousel.min.js"></script>
<script type="text/javascript" src="assets/js/lib/jquery.sharrre.min.js"></script>
<script type="text/javascript" src="assets/js/main.js"></script>
<script type="text/javascript" src="assets/js/validator.js"></script>
<script type="text/javascript" src="assets/js/html5.js"></script>

<script src="js/bootstrap.min.js"></script>
<script src="js/bootstrap-modal.js"></script>


</body>
</html>