#ifndef UDMSprInetCatalogCFH                  
#define UDMSprInetCatalogCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprInetCatalogCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprInetCatalogCF();                                                           
   ~TDMSprInetCatalogCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
