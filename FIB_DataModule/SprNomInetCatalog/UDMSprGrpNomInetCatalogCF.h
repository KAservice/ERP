#ifndef UDMSprGrpNomInetCatalogCFH                  
#define UDMSprGrpNomInetCatalogCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprGrpNomInetCatalogCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprGrpNomInetCatalogCF();                                                           
   ~TDMSprGrpNomInetCatalogCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
