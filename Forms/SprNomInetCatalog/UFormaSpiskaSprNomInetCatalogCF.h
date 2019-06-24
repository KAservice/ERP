#ifndef UFormaSpiskaSprNomInetCatalogCFH                  
#define UFormaSpiskaSprNomInetCatalogCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprNomInetCatalogCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprNomInetCatalogCF();                                                           
   ~TFormaSpiskaSprNomInetCatalogCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
