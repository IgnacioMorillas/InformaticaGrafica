En la practica se ha realizado el desarollo delos objetos:
ESFERA, CONO, CILINDRO, CUBO, PIRAMIDE, OBJETO_PLY, OBJETO_PLY_REV.

Con sus correspondientes pintados de:
POINTS, EDGES, SOLID, SOLID_CHES.

Los objetos por revolucion detectan cuando son introducidos de arriba abajo los perfiles, dandoles la vuelta.

El acceso de las teclas es el siguiente:
'Q':exit;

	'1':modo=POINTS;
	'2':modo=EDGES;
	'3':modo=SOLID;
	'4':modo=SOLID_CHESS;

        'P':t_objeto=PIRAMIDE;
        'C':t_objeto=CUBO;
        'O':t_objeto=OBJETO_PLY;(pintará "beethoven.ply")
        'R':t_objeto=ROTACION;
	'M':t_objeto=CONO;
	'E':t_objeto=ESFERA;
	'V':t_objeto=OBJETO_PLY_REV;(pintará por revolucion un peon leido del fichero "prueba.ply")

Si se quiere introducir otra figura distinta como el "beethoven.ply" basta con meterse en el fichero makefile y cambiar beethoven por el nombre del nuevo fichero.

Si se quiere introducir otra perfil como el de"prueva.ply" basta con meterse en el fichero makefile y cambiar prueba por el nombre del nuevo fichero con el perfil.
