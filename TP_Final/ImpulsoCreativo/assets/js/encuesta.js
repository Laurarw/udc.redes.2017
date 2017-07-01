
var resultado; 
resultado = ''; 
function validar_rgroup(rgroup) { 
var algo_pinchado; 
algo_pinchado = 'no'; 
for (var i=0; i<rgroup.length; i++) { 
if (rgroup[i].checked) { 
algo_pinchado = 'si'; 
break; 
} 
} 

if (algo_pinchado == 'no'){ 
resultado = resultado + 'Selecciona un valor para la '  + rgroup[0].name + '\n'; 
} 
} 
function validar_encuesta(formulario) { 
validar_rgroup(formulario.primera); 
validar_rgroup(formulario.segunda); 
validar_rgroup(formulario.tercera);
validar_rgroup(formulario.cuarta);
validar_rgroup(formulario.quinta);
validar_rgroup(formulario.sexta);
validar_rgroup(formulario.septima);
validar_rgroup(formulario.octava);
validar_rgroup(formulario.novena);
validar_rgroup(formulario.decima);
validar_rgroup(formulario.decima_primera);
validar_rgroup(formulario.decima_segunda);
if (resultado != '') { 
resultado = 'Cada pregunta debe tener una elección: \n' + resultado; 
alert(resultado); 
return false;
} 
} 

