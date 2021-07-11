//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>
#include "file_ply_stl.hpp"

using namespace std;

const float AXIS_SIZE=5000;
typedef enum{POINTS,EDGES,SOLID_CHESS,SOLID} _modo;

//*************************************************************************
// clase punto
//*************************************************************************

class _puntos3D
{
public:


	_puntos3D();
void 	draw_puntos(float r, float g, float b, int grosor);

vector<_vertex3f> vertices;
};

//*************************************************************************
// clase triángulo
//*************************************************************************

class _triangulos3D: public _puntos3D
{
public:

	_triangulos3D();
void 	draw_aristas(float r, float g, float b, int grosor);
void    draw_solido(float r, float g, float b);
void 	draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2);
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

vector<_vertex3i> caras;
};


//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo: public _triangulos3D
{
public:

	_cubo(float tam=0.5);
};


//*************************************************************************
// clase piramide
//*************************************************************************

class _piramide: public _triangulos3D
{
public:

	_piramide(float tam=0.5, float al=0.75);
};

//*************************************************************************
// clase objeto ply
//*************************************************************************

class _objeto_ply: public _triangulos3D
{
public:
   _objeto_ply();

int   parametros(char *archivo);
};

//************************************************************************
// objeto por revolución
//************************************************************************

class _rotacion: public _triangulos3D
{
public:
       _rotacion();
void  parametros(vector<_vertex3f> perfil1, int num1, int tapas, double angulo=(2*M_PI));

vector<_vertex3f> perfil;
int num;
};


//************************************************************************
// objeto articulado: tanque
//************************************************************************

class _chasis: public _triangulos3D
{
public:
       _chasis();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

float altura;

protected:
_rotacion  rodamiento;
_cubo  base;
};

//************************************************************************

class _torreta: public _triangulos3D
{
public:
       _torreta();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

float altura;
float anchura;

protected:
_cubo  base;
_piramide parte_trasera;
};

//************************************************************************

class _tubo: public _triangulos3D
{
public:
       _tubo();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

protected:
_rotacion tubo_abierto; // caña del cañón
};

//************************************************************************

class _tanque: public _triangulos3D
{
public:
       _tanque();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

float giro_tubo;
float giro_torreta;

float giro_tubo_min;
float giro_tubo_max;

protected:
_chasis  chasis;
_torreta  torreta;
_tubo     tubo;
};

//************************************************************************

//---------------------------
//PIEZAS

class _cilindro: public _triangulos3D
{
public:
       _cilindro();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

protected:
_rotacion cilindro; // caña del cañón
};

//_______________________________________-
class _rueda: public _triangulos3D
{
public:
      _rueda();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

protected:
_cilindro cilindro1;
};

//_______________________________________-
class _articulaciones: public _triangulos3D
{
public:
      _articulaciones();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

protected:
_cilindro cilindro;
};

//_______________________________________-
class _brazos: public _triangulos3D
{
public:
      _brazos();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

protected:
_articulaciones articulaciones;
_cubo cubo;
};

//_______________________________________-
class _pala: public _triangulos3D
{
public:
      _pala();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

protected:
_rotacion rotacion;
//_cilindro cilindro;
};

//_______________________________________-
class _base: public _triangulos3D
{
public:
      _base();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

protected:
_rueda rueda;
_cubo cubo;
_brazos brazos;
_pala pala;
};

//____________PALA_ARTI2_____________________-
class _PALA_ARTI2: public _triangulos3D
{
public:
      _PALA_ARTI2();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor, float alfa, float beta, float gama);
double zeta;
protected:
_pala pala;
_brazos brazos;
};

//____________PALA_ARTI2_ARTI1______________________-
class _PALA_ARTI2_ARTI1: public _triangulos3D
{
public:
      _PALA_ARTI2_ARTI1();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor, float alfa, float beta, float gama);

protected:
_PALA_ARTI2 pala_arti2;
_brazos brazos;
};

//_____________COMPLETO_____________________-
class _COMPLETO: public _triangulos3D
{
public:
      _COMPLETO();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);
double alfa=0;
double beta=0;
double gama=0;
bool activar=false;
protected:
_PALA_ARTI2_ARTI1 pala_arti2_base;
_base base;
};
