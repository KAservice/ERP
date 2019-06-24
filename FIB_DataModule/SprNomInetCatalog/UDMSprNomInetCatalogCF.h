#ifndef UDMSprNomInetCatalogCFH                  
#define UDMSprNomInetCatalogCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprNomInetCatalogCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprNomInetCatalogCF();                                                           
   ~TDMSprNomInetCatalogCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
