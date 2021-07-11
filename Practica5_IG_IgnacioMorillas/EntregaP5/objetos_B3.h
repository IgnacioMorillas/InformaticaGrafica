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
typedef enum{POINTS,EDGES,SOLID_CHESS,SOLID,SOLID_ILLUMINATED_FLAT,
             SOLID_ILLUMINATED_GOURAUD} _modo;

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
void    draw_solido(float r, float g, float b,bool pintarInteraccion=false,vector<bool> pintado ={});
void 	draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2);
void 	draw_iluminacion_plana( );
void 	draw_iluminacion_suave( );

void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,int material=0,bool pintarInteraccion=false,vector<bool> pintado ={});

void	calcular_normales_caras();
void 	calcular_normales_vertices();

vector<_vertex3i> caras;

vector<_vertex3f> normales_caras;
vector<_vertex3f> normales_vertices;

bool b_normales_caras;
bool b_normales_vertices;

_vertex4f ambiente_difusa;     //coeficientes ambiente y difuso
_vertex4f especular;           //coeficiente especular
float brillo;                  //exponente del brillo
};


//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo: public _triangulos3D
{
public:

  vector<bool> espintado={false,false,false,false,false,false,false,false,false,false,false,false};
	_cubo(float tam=0.5);
};


//*************************************************************************
// clase piramide
//*************************************************************************

class _piramide: public _triangulos3D
{
public:

	_piramide(float tam=0.5, float al=0.75);
  bool espintado=false;

};
class _esfera: public _triangulos3D
{
  public:
    _esfera();
		void generar(float radio,int num,int numPerfil);

};

//*************************************************************************
// clase objeto ply
//*************************************************************************

class _objeto_ply: public _triangulos3D
{
public:
   _objeto_ply();

int   parametros(char *archivo);
bool espintado=false;

};

//************************************************************************
// objeto por revolución
//************************************************************************

class _rotacion: public _triangulos3D
{
public:
       _rotacion();
void  parametros(vector<_vertex3f> perfil1, int num1, int tapas, double angulo=(2*M_PI));
bool espintado=false;

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
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,int material=0);

float altura;

bool espintado=false;
_rotacion  rodamiento;
_cubo  base;
};

//************************************************************************

class _torreta: public _triangulos3D
{
public:
       _torreta();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,int material=0);

float altura;
float anchura;

bool espintado=false;

_cubo  base;
_piramide parte_trasera;
};

//************************************************************************

class _tubo: public _triangulos3D
{
public:
       _tubo();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,int material=0);

bool espintado=false;
_rotacion tubo_abierto; // caña del cañón
};

//************************************************************************

class _tanque: public _triangulos3D
{
public:
       _tanque();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor, int material=0);

float giro_tubo;
float giro_torreta;

float giro_tubo_min;
float giro_tubo_max;

bool espintado=false;
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
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,int material=0);
bool espintado=false;

_rotacion cilindro; // caña del cañón
};

//_______________________________________-
class _rueda: public _triangulos3D
{
public:
      _rueda();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,int material=0);
bool espintado=false;

_cilindro cilindro1;
};

//_______________________________________-
class _articulaciones: public _triangulos3D
{
public:
      _articulaciones();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,int material=0);
bool espintado=false;

_cilindro cilindro;
};

//_______________________________________-
class _brazos: public _triangulos3D
{
public:
      _brazos();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,int material=0);
bool espintado=false;

_articulaciones articulaciones;
_cubo cubo;
};

//_______________________________________-
class _pala: public _triangulos3D
{
public:
      _pala();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,int material=0);
bool espintado=false;

_rotacion rotacion;
//_cilindro cilindro;
};

//_______________________________________-
class _base: public _triangulos3D
{
public:
      _base();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,int material=0,double incr=0);
bool espintado=false;

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
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor, float alfa, float beta, float gama,int material=0,double incr=0);
double zeta;
_pala pala;
_brazos brazos;
bool espintado=false;

};

//____________PALA_ARTI2_ARTI1______________________-
class _PALA_ARTI2_ARTI1: public _triangulos3D
{
public:
      _PALA_ARTI2_ARTI1();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor, float alfa, float beta, float gama,int material=0,double incr=0);
bool espintado=false;

_PALA_ARTI2 pala_arti2;
_brazos brazos;
};

//_____________COMPLETO_____________________-
class _COMPLETO: public _triangulos3D
{
public:
      _COMPLETO();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor,int material=0,double incr=0);
double alfa=0;
double beta=0;
double gama=0;
bool activar=false;
_PALA_ARTI2_ARTI1 pala_arti2_base;
_base base;
bool espintado=false;

};
