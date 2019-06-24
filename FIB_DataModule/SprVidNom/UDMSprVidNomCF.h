#ifndef UDMSprVidNomCFH                  
#define UDMSprVidNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprVidNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprVidNomCF();                                                           
   ~TDMSprVidNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
