#ifndef USR_FormaOstatkiTovarovCFH                  
#define USR_FormaOstatkiTovarovCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TSR_FormaOstatkiTovarovCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TSR_FormaOstatkiTovarovCF();                                                           
   ~TSR_FormaOstatkiTovarovCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
