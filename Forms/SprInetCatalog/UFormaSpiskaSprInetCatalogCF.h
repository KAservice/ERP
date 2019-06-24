#ifndef UFormaSpiskaSprInetCatalogCFH                  
#define UFormaSpiskaSprInetCatalogCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprInetCatalogCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprInetCatalogCF();                                                           
   ~TFormaSpiskaSprInetCatalogCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
