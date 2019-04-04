
// Final Fantasy XIII-2  Acertijo del reloj
// Guillermo Arriaga García   Abril de 2012

#include <iostream>
#include <list>

using namespace std;


struct casillas{
   int numero;
   bool eliminada;
};


int main(){

   unsigned int i,n=0, adelante, atras;
   bool solucion=0;
   casillas* casilla=NULL;
   list<int> revision,viaje;
   list<int>::iterator it;
   
   system("CLS");
   cout<<"\n\n\tNumero de casillas: ";
   cin>>n;
   casilla=new casillas[n];
   cout<<"\n\n\tValor de las casillas: \n";
   
   for(i=0;i<n;i++){
      cout<<"\nCasilla["<<i+1<<"] = ";
      cin>>casilla[i].numero;
      casilla[i].eliminada=0;
   }
   
   for(i=0;i<n && solucion==0;i++){
      revision.clear();
      viaje.clear();
      
      for(int j=0; j<n ; j++){
         casilla[j].eliminada=0;
      }
      
      revision.push_back(i);
      
      while( solucion==0 && revision.size()!=0) {
         if(casilla[revision.back()].eliminada==0){
            casilla[revision.back()].eliminada=1;
            viaje.push_back(revision.back());
            
            if(viaje.size()==n){
               solucion=1;
            }
            else{
               adelante=(revision.back()+casilla[revision.back()].numero)%n;
               atras=(revision.back()+n-casilla[revision.back()].numero)%n;
               
               if(casilla[atras].eliminada==0){
                  revision.push_back(atras);
               }
               if(casilla[adelante].eliminada==0){
                  revision.push_back(adelante);
               }
            }
            
         }
         else{
            casilla[revision.back()].eliminada=0;
            revision.pop_back();
            viaje.pop_back();
         }
      
      }
   }
   
   if(solucion==1){
      cout<<"\n\n\tSOLUCION: ";
      for(it=viaje.begin(); it!=viaje.end(); it++){
         cout<<" "<<(char)(*it+(int)('a'));
      }
      cout<<"\n\tque son las posiciones: ";
      for(it=viaje.begin(); it!=viaje.end(); it++){
         cout<<" "<<(*it+1);
      }

   }
   else{
      cout<<"\n\n\tNO EXISTE SOLUCION";
   }
   
   cout<<endl;
   system("PAUSE");
   delete [] casilla;
   return 0;
}
