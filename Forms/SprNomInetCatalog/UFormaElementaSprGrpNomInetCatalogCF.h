#ifndef UFormaElementaSprGrpNomInetCatalogCFH                  
#define UFormaElementaSprGrpNomInetCatalogCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprGrpNomInetCatalogCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprGrpNomInetCatalogCF();                                                           
   ~TFormaElementaSprGrpNomInetCatalogCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
