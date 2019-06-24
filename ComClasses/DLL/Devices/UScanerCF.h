#ifndef UScanerCFH                  
#define UScanerCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TScanerCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TScanerCF();                                                           
   ~TScanerCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
