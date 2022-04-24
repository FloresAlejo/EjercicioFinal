#include <iostream>
#include <cstdlib>

using namespace std;

/* PRE-PARCIAL 27.10.21
Una empresa dedicada a la venta de artículos del hogar, con 30
sucursales, desea conocer la comisión que debe abonar
a c/u de sus vendedores que es del 5% o 10% en caso de ser >= a $
100.000, del monto total vendido en el mes.
Se solicita se informe los Totales por: Vendedor, Sucursal y
Generales.
Se dispone de los siguientes datos: Nro. Sucursal (1/30), Nro. de
Vendedor (1/200) e Importe de cada venta.
(entre $ 1000 y $ 100.000).
Los registros se hallan ordenados por Nro. de Sucursal y Nro. de
vendedor, ambos en orden ascendente. Para finalizar Sucursal =999.
Por cada corte de control Se deberá informar:
Total por cada vendedor:
a) Nro. de Sucursal.
b) Nro. de vendedor.
c) Cantidad de facturas emitidas.
d Importe total de sus ventas en el mes.
e) Comisión a abonar (5% o 10% según corresponda, del total de sus
ventas).
Total por cada Sucursal:
a) Nro. de Sucursal.
b) Cantidad de facturas emitidas en el mes.
c) Importe total de ventas en el mes.
d) Importe de Comisión a abonar.
Totales Generales:
a) Cantidad de facturas emitidas en el mes.
b) El importe total de ventas.
c) Importe total de Comisión a abonar.
Se requiere: Diagrama y su Codificación en lenguaje C++, aplicando cortes
de control por:
Sucursal y Vendedor, y aplicando funciones (utilizando DO WHILE)
Sucursal y Vendedor e Importe de Venta.*/

int fun_suc(int,int,int);
int fun_empl(int,int);

int main(int argc, char** argv) {
	
	int nrosuc,nrosucx,facsuc=0,ventsuc=0;
	int nroempl,nroemplx,imp,ventempl=0,canfac=0;
	int totalvent=0,totalfac=0;
	float comsuc=0,comempl=0,totalcom=0;
	
	nrosuc=fun_suc(1,30,99);
	
	while(nrosuc!=99)
	{
		nrosucx=nrosuc;
		nroempl=fun_empl(1,200);
		
		while(nrosuc==nrosucx&&nrosuc!=99)
		{
			nroemplx=nroempl;
			
			while(nroemplx==nroempl&&nrosucx==nrosuc&&nrosuc!=99)
			{
				do{
					cout<<" Ingrese importe de venta(1000/100.000): "<<endl;
					cin>>imp;
				}while(imp<1000||imp>100000);
				
			ventempl+=imp; canfac++;
			
			nrosuc=fun_suc(1,30,99);
			
			if (nrosuc!=99&&nrosuc==nrosucx) nroempl=fun_empl(1,200);
			
			}
			
		if (ventempl>=100000) comempl=ventempl*0.10;
		else comempl=ventempl*0.05;
		
		cout<<endl<<"-----------------------------------------------------------------------"<<endl;
		cout<<endl<<" * VENDEDOR: "<<nroemplx<<" *"<<endl;
		cout<<" SUCURSAL: "<<nrosucx<<endl;
		cout<<" CANTIDAD DE VENTAS: "<<canfac<<endl;
		cout<<" IMPORTE VENTAS: "<<ventempl<<endl;
		cout<<" COMISION A PAGAR: "<<comempl<<endl;
		cout<<endl<<"-----------------------------------------------------------------------"<<endl;
		
		if (nrosuc==nrosucx&&nrosucx!=99) cout<<endl<<" ACCEDIO A LA SUCURSAL: "<<nrosuc<<endl;
		if (nrosuc==nrosucx&&nrosucx!=99) cout<<" ACCEDIO AL VENDEDOR: "<<nroempl<<endl;
		cout<<endl;
		
		facsuc+=canfac; ventsuc+=ventempl; comsuc+=comempl;
		canfac=0; ventempl=0;  
		}
		
	if(nrosucx!=99)
		{
		cout<<endl<<"-----------------------------------------------------------------------"<<endl;
		cout<<endl<<" * SUCURSAL: "<<nrosucx<<" *"<<endl;
		cout<<" CANTIDAD DE FACTURAS EMITIDAS: "<<facsuc<<endl;
		cout<<" TOTAL DE VENTAS SUCURSAL: "<<ventsuc<<endl;
		cout<<" TOTAL COMISIONES A PAGAR: "<<comsuc<<endl;
		cout<<endl<<"-----------------------------------------------------------------------"<<endl;
		
		if(nrosuc!=99)
		{
		cout<<endl<<" ACCEDIO A LA SUCURSAL: "<<nrosuc<<endl;
		cout<<endl;
		}
		}
	totalfac+=facsuc; totalvent+=ventsuc; totalcom+=comsuc;
	ventsuc=0; comsuc=0; facsuc=0;
		
	}
	
	cout<<endl<<"-----------------------------------------------------------------------"<<endl;
	cout<<endl<<" * TOTALES GENERALES: *"<<endl;
	cout<<" CANTIDAD DE FACTURAS EMITIDAS: "<<totalfac<<endl;
	cout<<" TOTAL DE VENTAS SUCURSALES: "<<totalvent<<endl;
	cout<<" TOTAL COMISIONES A PAGAR: "<<totalcom<<endl;
	cout<<endl<<"-----------------------------------------------------------------------"<<endl;
	
	
	return 0;
}

int fun_suc(int x,int y, int z){
	int nrosuc;
	
	do{
		cout<<" Ingrese Nro de sucursal(1/30)/ FIN=99: "<<endl;
		cin>>nrosuc;
		
	}while(nrosuc<x||nrosuc>y&&nrosuc!=99);

	return nrosuc;
}

int fun_empl (int x,int y){
	int nroemple;
	
	do{
		cout<<" Ingrese Nro de empleado(1/200): "<<endl;
		cin>>nroemple;
		
	}while(nroemple<x||nroemple>y);
	
	return nroemple;
}
