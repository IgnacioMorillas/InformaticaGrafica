//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include "objetos_B2.h"
#include "file_ply_stl.hpp"
#include<algorithm>


//*************************************************************************
// _puntos3D
//*************************************************************************

_puntos3D::_puntos3D()
{
}

//*************************************************************************
// dibujar puntos
//*************************************************************************

void _puntos3D::draw_puntos(float r, float g, float b, int grosor)
{
int i;
glPointSize(grosor);
glColor3f(r,g,b);
glBegin(GL_POINTS);
for (i=0; i < vertices.size() ;i++){
	glVertex3fv((GLfloat *) &vertices[i]);
	}
glEnd();
}


//*************************************************************************
// _triangulos3D
//*************************************************************************

_triangulos3D::_triangulos3D()
{
}


//*************************************************************************
// dibujar en modo arista
//*************************************************************************

void _triangulos3D::draw_aristas(float r, float g, float b, int grosor)
{
int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
glLineWidth(grosor);
glColor3f(r,g,b);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();
}

//*************************************************************************
// dibujar en modo sólido
//*************************************************************************

void _triangulos3D::draw_solido(float r, float g, float b)
{
	int i;
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

	glColor3f(r,g,b);
	glBegin(GL_TRIANGLES);
	for (i=0;i<caras.size();i++){
		glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
		}
	glEnd();
}

//*************************************************************************
// dibujar en modo sólido con apariencia de ajedrez
//*************************************************************************

void _triangulos3D::draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2)
{
	int i;
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glBegin(GL_TRIANGLES);
	for (i=0;i<caras.size();i++){
		if(i%2==0){
			glColor3f(r1,g1,b1);
		}
		else{
			glColor3f(r2,g2,b2);
		}
		glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
		}
	glEnd();
}

//*************************************************************************
// dibujar con distintos modos
//*************************************************************************

void _triangulos3D::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{
switch (modo){
	case POINTS:draw_puntos(r1, g1, b1, grosor);break;
	case EDGES:draw_aristas(r1, g1, b1, grosor);break;
	case SOLID_CHESS:draw_solido_ajedrez(r1, g1, b1, r2, g2, b2);break;
	case SOLID:draw_solido(r1, g1, b1);break;
	}
}

//*************************************************************************
// clase cubo
//*************************************************************************

_cubo::_cubo(float tam)
{
//vertices
	vertices.resize(8);
	///-vertices cara de abajo
	vertices[0].x=-tam;vertices[0].y=-tam;vertices[0].z=-tam;
	vertices[1].x=tam;vertices[1].y=-tam;vertices[1].z=-tam;
	vertices[2].x=tam;vertices[2].y=-tam;vertices[2].z=tam;
	vertices[3].x=-tam;vertices[3].y=-tam;vertices[3].z=tam;
	///-vertices cara de arriba
	vertices[4].x=-tam;vertices[4].y=tam;vertices[4].z=tam;
	vertices[5].x=-tam;vertices[5].y=tam;vertices[5].z=-tam;
	vertices[6].x=tam;vertices[6].y=tam;vertices[6].z=-tam;
	vertices[7].x=tam;vertices[7].y=tam;vertices[7].z=tam;

// triangulos
	caras.resize(12);
	//Cara base
	caras[0]._0=0;caras[0]._1=3;caras[0]._2=1;
	caras[1]._0=3;caras[1]._1=2;caras[1]._2=1;
	//caratrasera
	caras[2]._0=7;caras[2]._1=2;caras[2]._2=3;
	caras[3]._0=4;caras[3]._1=7;caras[3]._2=3;
	//cara izq
	caras[4]._0=4;caras[4]._1=3;caras[4]._2=0;
	caras[5]._0=0;caras[5]._1=5;caras[5]._2=4;
	//cara frontal
	caras[6]._0=0;caras[6]._1=5;caras[6]._2=1;
	caras[7]._0=1;caras[7]._1=5;caras[7]._2=6;
	//cara derecha
	caras[8]._0=6;caras[8]._1=2;caras[8]._2=1;
	caras[9]._0=2;caras[9]._1=6;caras[9]._2=7;
	//cara superior
	caras[10]._0=7;caras[10]._1=6;caras[10]._2=4;
	caras[11]._0=4;caras[11]._1=6;caras[11]._2=5;
}


//*************************************************************************
// clase piramide
//*************************************************************************

_piramide::_piramide(float tam, float al)
{
caras.clear();
vertices.clear();
//vertices
vertices.resize(5);
vertices[0].x=-tam;vertices[0].y=0;vertices[0].z=tam;
vertices[1].x=tam;vertices[1].y=0;vertices[1].z=tam;
vertices[2].x=tam;vertices[2].y=0;vertices[2].z=-tam;
vertices[3].x=-tam;vertices[3].y=0;vertices[3].z=-tam;
vertices[4].x=0;vertices[4].y=al;vertices[4].z=0;

caras.resize(6);
caras[0]._0=0;caras[0]._1=1;caras[0]._2=4;
caras[1]._0=1;caras[1]._1=2;caras[1]._2=4;
caras[2]._0=2;caras[2]._1=3;caras[2]._2=4;
caras[3]._0=3;caras[3]._1=0;caras[3]._2=4;
caras[4]._0=3;caras[4]._1=1;caras[4]._2=0;
caras[5]._0=3;caras[5]._1=2;caras[5]._2=1;
}

//*************************************************************************
// clase objeto ply
//*************************************************************************


_objeto_ply::_objeto_ply()
{
   // leer lista de coordenadas de vértices y lista de indices de vértices

}



int _objeto_ply::parametros(char *archivo)
{
int n_ver,n_car;

vector<float> ver_ply ;
vector<int>   car_ply ;

_file_ply::read(archivo, ver_ply, car_ply );

n_ver=ver_ply.size()/3;
n_car=car_ply.size()/3;

printf("Number of vertices=%d\nNumber of faces=%d\n", n_ver, n_car);

vertices.resize(n_ver);
caras.resize(n_car);

//------------------------------------------------------------------------
vertices.clear();
caras.clear();

_vertex3f new_vertices;

for(int i=0; i<ver_ply.size();i+=3){
	new_vertices.x=ver_ply[i];
	new_vertices.y=ver_ply[i+1];
	new_vertices.z=ver_ply[i+2];
	vertices.push_back(new_vertices);
}

_vertex3i new_caras;

for(int i=0; i<car_ply.size()-6;i+=3){

	new_caras._0=car_ply[i];
	new_caras._1=car_ply[i+1];
	new_caras._2=car_ply[i+2];

	caras.push_back(new_caras);
}


//------------------------------------------------------------------------
return(0);
}


//------------------------------------------------------------------------
//clase Cono
//------------------------------------------------------------------------
_cono::_cono(float radio, float altura,int num){
	//_rotacion rotacion;
	//vector<_vertex3f> perfil {{radio,(-altura/2),0}
	//													};
}

void  _cono::generar(float radio, float altura,int num){
		caras.clear();
		vertices.clear();
		//_rotacion rotacion;
		vector<_vertex3f> perfil {{radio,(-altura/2),0}
		};
		int i,j;
		_vertex3f vertice_aux;
		_vertex3i cara_aux;
		int num_aux;
		// tratamiento de los vértice

		num_aux=perfil.size();


		vertices.resize(num_aux*num);
		for (j=0;j<num;j++)
		  {
				for (i=0;i<num_aux;i++)
		     {
		      vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*num))+
		                    perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
		      vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*num))+
		                    perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
		      vertice_aux.y=perfil[i].y;
		      vertices[i+j*num_aux]=vertice_aux;
		     }
		  }

		 // tapa inferior

		if (fabs(perfil[0].x)>0.0)
		  {
				if(perfil.size()==1){
					vertice_aux.x=0;
				  vertice_aux.z=0;
				  vertice_aux.y=perfil[0].y;
					vertices.push_back(vertice_aux);

					for(int i=0;i<num-1;i++){
						//for(int j=0;j<num_aux-1;j++){
							cara_aux._0 = i;
							cara_aux._1 = vertices.size()-1;
							cara_aux._2 = (i+1);

							caras.push_back(cara_aux);
					//	}
					}
				}
				else{

				vertice_aux.x=0;
			  vertice_aux.z=0;
			  vertice_aux.y=perfil[0].y;
				vertices.push_back(vertice_aux);

				for(int i=0;i<num-1;i++){
					for(int j=0;j<num_aux-1;j++){
						cara_aux._0 = i*num_aux+j;
						cara_aux._1 = vertices.size()-1;
						cara_aux._2 = (i+1)*num_aux;

						caras.push_back(cara_aux);
					}
				}
			}
				//FUNCIONA
				/*
				for(j=0;j<num_aux-1;j++){

					cara_aux._0 = (num-1)*num_aux+j;
					cara_aux._1 = vertices.size()-1;
					cara_aux._2 = j;

				caras.push_back(cara_aux);
			}
			*/
			cara_aux._0 = (num-1)*num_aux;
			cara_aux._1 = vertices.size()-1;
			cara_aux._2 = 0;

			caras.push_back(cara_aux);

		  }

		 // tapa superior

		 if (fabs(perfil[num_aux-1].x)>0.0)
		  {
				if(perfil.size()==1){
					vertice_aux.x=0;
					vertice_aux.z=0;
					vertice_aux.y=perfil[1].y+altura;
					vertices.push_back(vertice_aux);

					for(int i=0;i<num-1;i++){
					//	for(int j=0;j<num_aux-1;j++){
							cara_aux._0 = i;
							cara_aux._1 = vertices.size()-1;
							cara_aux._2 = (i+1);

							caras.push_back(cara_aux);
				//		}
					}
				}
				else{
				vertice_aux.x=0;
				vertice_aux.z=0;
				vertice_aux.y=perfil[1].y;
				vertices.push_back(vertice_aux);

				for(int i=0;i<num-1;i++){
					for(int j=0;j<num_aux-1;j++){
						cara_aux._0 = (i)*num_aux+j+1;
						cara_aux._1 = vertices.size()-1;
						cara_aux._2 = (i+1)*num_aux+j+1;

						caras.push_back(cara_aux);
					}
				}
			}

			cara_aux._0 = (num-1)*num_aux+num_aux-1;
			cara_aux._1 = vertices.size()-1;
			cara_aux._2 = num_aux-1;

		caras.push_back(cara_aux);
		}

		}


//************************************************************************
// objeto por revolucion
//************************************************************************

_rotacion::_rotacion()
{

}


void _rotacion::parametros(vector<_vertex3f> perfil, int num, float altura)
{
	caras.clear();
	vertices.clear();

int i,j;
_vertex3f vertice_aux;
_vertex3i cara_aux;
int num_aux;
// tratamiento de los vértice

num_aux=perfil.size();
//Por si hay que hacerle la inversa
if(perfil[0].y>perfil[1].y)
	reverse(perfil.begin(),perfil.end());

vertices.resize(num_aux*num);
for (j=0;j<num;j++)
  {
		for (i=0;i<num_aux;i++)
     {
      vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
      vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
      vertice_aux.y=perfil[i].y;
      vertices[i+j*num_aux]=vertice_aux;
     }
  }



// tratamiento de las caras

for(int i=0;i<num-1;i++){

	for(int j=0;j<num_aux-1;j++){

		cara_aux._0 = i*num_aux+j;
		cara_aux._1 = ((i+1)*num_aux+j);
		cara_aux._2 = i*num_aux+(j+1);

		caras.push_back(cara_aux);
		cara_aux._0 = (i+1)*num_aux+j;
		cara_aux._1 = (i+1)*num_aux+(j+1);
		cara_aux._2 = ((i)*num_aux+j+1);

		caras.push_back(cara_aux);
	}
}


//ultima cara

for(j=0;j<num_aux-1;j++){

cara_aux._0 = (num-1)*num_aux+j;
cara_aux._1 = j;
cara_aux._2 = (num-1)*num_aux+(j+1);

caras.push_back(cara_aux);

cara_aux._0 = j;
cara_aux._1 = (j+1);
cara_aux._2 = ((num-1)*num_aux+j+1);

caras.push_back(cara_aux);
}
//-----------------------------------------------

 // tapa inferior

if (fabs(perfil[0].x)>0.0)
  {
		if(perfil.size()==1){
			vertice_aux.x=0;
		  vertice_aux.z=0;
		  vertice_aux.y=perfil[0].y;
			vertices.push_back(vertice_aux);

			for(int i=0;i<num-1;i++){
				//for(int j=0;j<num_aux-1;j++){
					cara_aux._0 = i;
					cara_aux._1 = vertices.size()-1;
					cara_aux._2 = (i+1);

					caras.push_back(cara_aux);
			//	}
			}
		}
		else{

		vertice_aux.x=0;
	  vertice_aux.z=0;
	  vertice_aux.y=perfil[0].y;
		vertices.push_back(vertice_aux);

		for(int i=0;i<num-1;i++){
			//for(int j=0;j<num_aux-1;j++){
				cara_aux._0 = i*num_aux;
				cara_aux._1 = vertices.size()-1;
				cara_aux._2 = (i+1)*num_aux;

				caras.push_back(cara_aux);
			//}
		}
	}
		//FUNCIONA
		/*
		for(j=0;j<num_aux-1;j++){

			cara_aux._0 = (num-1)*num_aux+j;
			cara_aux._1 = vertices.size()-1;
			cara_aux._2 = j;

		caras.push_back(cara_aux);
	}
	*/
	cara_aux._0 = (num-1)*num_aux;
	cara_aux._1 = vertices.size()-1;
	cara_aux._2 = 0;

	caras.push_back(cara_aux);

  }

 // tapa superior

 if (fabs(perfil[num_aux-1].x)>0.0)
  {
		if(perfil.size()==1){
			vertice_aux.x=0;
			vertice_aux.z=0;
			vertice_aux.y=perfil[1].y+altura;
			vertices.push_back(vertice_aux);

			for(int i=0;i<num-1;i++){
					cara_aux._0 = i;
					cara_aux._1 = vertices.size()-1;
					cara_aux._2 = (i+1);

					caras.push_back(cara_aux);
			}
		}
		else{
		vertice_aux.x=0;
		vertice_aux.z=0;
		vertice_aux.y=perfil[num_aux-1].y;
		vertices.push_back(vertice_aux);

		for(int i=0;i<num-1;i++){
			//for(int j=0;j<num_aux-1;j++){
				cara_aux._0 = (i)*num_aux+num_aux-1;
				cara_aux._1 = vertices.size()-1;
				cara_aux._2 = (i+1)*num_aux+num_aux-1;

				caras.push_back(cara_aux);
			//}
		}
	}

	cara_aux._0 = (num-1)*num_aux+num_aux-1;
	cara_aux._1 = vertices.size()-1;
	cara_aux._2 = num_aux-1;

caras.push_back(cara_aux);
}

}

//------------------------------------------------------------------------
//clase esfera
//------------------------------------------------------------------------
_esfera::_esfera(){
}

void  _esfera::generar(float radio,int num,int numPerfil){

	caras.clear();
	vertices.clear();
	float angIni = M_PI/2, angCal = M_PI/(numPerfil-1);
	vector<_vertex3f> perfil;
	_vertex3f perfil_aux;
	int aux =numPerfil;
	for(int i = 0; i < aux; ++i){
			perfil_aux.x = radio * cos(angIni);
			perfil_aux.y = radio * sin(angIni);
			perfil_aux.z = 0;
			if(perfil_aux.x>0.0001)
				perfil.push_back(perfil_aux);
			else{
				numPerfil--;
			}
			angIni -= angCal;
}


int i,j;
_vertex3f vertice_aux;
_vertex3i cara_aux;
int num_aux;
// tratamiento de los vértice

num_aux=perfil.size();
if(perfil[0].y>perfil[1].y)
	reverse(perfil.begin(),perfil.end());

vertices.resize(num_aux*num);
for (j=0;j<num;j++)
  {
		for (i=0;i<num_aux;i++)
     {
      vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
      vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
      vertice_aux.y=perfil[i].y;
      vertices[i+j*num_aux]=vertice_aux;
     }
  }



// tratamiento de las caras

for(int i=0;i<num-1;i++){

	for(int j=0;j<num_aux-1;j++){

		cara_aux._0 = i*num_aux+j;
		cara_aux._1 = ((i+1)*num_aux+j);
		cara_aux._2 = i*num_aux+(j+1);

		caras.push_back(cara_aux);
		cara_aux._0 = (i+1)*num_aux+j;
		cara_aux._1 = (i+1)*num_aux+(j+1);
		cara_aux._2 = ((i)*num_aux+j+1);

		caras.push_back(cara_aux);
	}
}

//ultima cara

for(j=0;j<num_aux-1;j++){

cara_aux._0 = (num-1)*num_aux+j;
cara_aux._1 = j;
cara_aux._2 = (num-1)*num_aux+(j+1);

caras.push_back(cara_aux);

cara_aux._0 = j;
cara_aux._1 = (j+1);
cara_aux._2 = ((num-1)*num_aux+j+1);

caras.push_back(cara_aux);
}



// tapa inferior

vector<_vertex3f> perfilaux(2);
vertice_aux.x=0;
vertice_aux.y=-radio;
vertice_aux.z=0;

vertices.push_back(vertice_aux);

for(int i=0;i<num-1;i++){
	cara_aux._0 = i*num_aux+0;
	cara_aux._1 = (i+1)*num_aux+0;
	cara_aux._2 = vertices.size()-1;

	caras.push_back(cara_aux);
}
cara_aux._0 = (num-1)*num_aux+0;
cara_aux._1 = vertices.size()-1;
cara_aux._2 = 0;

caras.push_back(cara_aux);

// tapa superior

vertice_aux.x=0;
vertice_aux.y=radio;
vertice_aux.z=0;

vertices.push_back(vertice_aux);

for(int i=0;i<num-1;i++){
	cara_aux._0 = i*num_aux+num_aux-1;

	cara_aux._1 = (i+1)*num_aux+num_aux-1;
	cara_aux._2 = vertices.size()-1;

	caras.push_back(cara_aux);
}
cara_aux._0 = (num-1)*num_aux+num_aux-1;
cara_aux._1 = vertices.size()-1;
cara_aux._2 = num_aux-1;

caras.push_back(cara_aux);

}


//______________________________________________-
//CLASE PLY revolucion
//____________________________________________-
_objeto_ply_rev::_objeto_ply_rev()
{
   // leer lista de coordenadas de vértices y lista de indices de vértices

}



int _objeto_ply_rev::parametros(char *archivo)
{
int n_ver,n_car;

vector<float> ver_ply ;
vector<int>   car_ply ;

_file_ply::read(archivo, ver_ply, car_ply );

n_ver=ver_ply.size()/3;
n_car=car_ply.size()/3;
int num=n_ver;
printf("Number of vertices=%d\nNumber of faces=%d\n", n_ver, n_car);

//vertices.resize(n_ver);
//caras.resize(n_car);

//------------------------------------------------------------------------

vector<_vertex3f> perfil;
_vertex3f perfil_aux;

for(int i=0; i<ver_ply.size();i+=3){
	perfil_aux.x=ver_ply[i];
	perfil_aux.y=ver_ply[i+1];
	perfil_aux.z=ver_ply[i+2];
	perfil.push_back(perfil_aux);

}

vertices.clear();
caras.clear();

int i,j;
_vertex3f vertice_aux;
_vertex3i cara_aux;
int num_aux;
// tratamiento de los vértice

num_aux=perfil.size();
//Por si hay que hacerle la inversa
if(perfil[0].y>perfil[1].y)
	reverse(perfil.begin(),perfil.end());

vertices.resize(num_aux*num);
for (j=0;j<num;j++)
  {
		for (i=0;i<num_aux;i++)
     {
      vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
      vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
      vertice_aux.y=perfil[i].y;
      vertices[i+j*num_aux]=vertice_aux;
     }
  }



// tratamiento de las caras

for(int i=0;i<num-1;i++){

	for(int j=0;j<num_aux-1;j++){

		cara_aux._0 = i*num_aux+j;
		cara_aux._1 = ((i+1)*num_aux+j);
		cara_aux._2 = i*num_aux+(j+1);

		caras.push_back(cara_aux);
		cara_aux._0 = (i+1)*num_aux+j;
		cara_aux._1 = (i+1)*num_aux+(j+1);
		cara_aux._2 = ((i)*num_aux+j+1);

		caras.push_back(cara_aux);
	}
}


//ultima cara

for(j=0;j<num_aux-1;j++){

cara_aux._0 = (num-1)*num_aux+j;
cara_aux._1 = j;
cara_aux._2 = (num-1)*num_aux+(j+1);

caras.push_back(cara_aux);

cara_aux._0 = j;
cara_aux._1 = (j+1);
cara_aux._2 = ((num-1)*num_aux+j+1);

caras.push_back(cara_aux);
}
//-----------------------------------------------

 // tapa inferior

if (fabs(perfil[0].x)>0.0)
  {
		if(perfil.size()==1){
			vertice_aux.x=0;
		  vertice_aux.z=0;
		  vertice_aux.y=perfil[0].y;
			vertices.push_back(vertice_aux);

			for(int i=0;i<num-1;i++){
				//for(int j=0;j<num_aux-1;j++){
					cara_aux._0 = i;
					cara_aux._1 = vertices.size()-1;
					cara_aux._2 = (i+1);

					caras.push_back(cara_aux);
			//	}
			}
		}
		else{

		vertice_aux.x=0;
	  vertice_aux.z=0;
	  vertice_aux.y=perfil[0].y;
		vertices.push_back(vertice_aux);

		for(int i=0;i<num-1;i++){
			//for(int j=0;j<num_aux-1;j++){
				cara_aux._0 = i*num_aux;
				cara_aux._1 = vertices.size()-1;
				cara_aux._2 = (i+1)*num_aux;

				caras.push_back(cara_aux);
			//}
		}
	}
		//FUNCIONA
		/*
		for(j=0;j<num_aux-1;j++){

			cara_aux._0 = (num-1)*num_aux+j;
			cara_aux._1 = vertices.size()-1;
			cara_aux._2 = j;

		caras.push_back(cara_aux);
	}
	*/
	cara_aux._0 = (num-1)*num_aux;
	cara_aux._1 = vertices.size()-1;
	cara_aux._2 = 0;

	caras.push_back(cara_aux);

  }

 // tapa superior

 if (fabs(perfil[num_aux-1].x)>0.0)
  {
		vertice_aux.x=0;
		vertice_aux.z=0;
		vertice_aux.y=perfil[num_aux-1].y;
		vertices.push_back(vertice_aux);

		for(int i=0;i<num-1;i++){
			//for(int j=0;j<num_aux-1;j++){
				cara_aux._0 = (i)*num_aux+num_aux-1;
				cara_aux._1 = vertices.size()-1;
				cara_aux._2 = (i+1)*num_aux+num_aux-1;

				caras.push_back(cara_aux);
			//}
		}

	cara_aux._0 = (num-1)*num_aux+num_aux-1;
	cara_aux._1 = vertices.size()-1;
	cara_aux._2 = num_aux-1;

caras.push_back(cara_aux);
}
}
