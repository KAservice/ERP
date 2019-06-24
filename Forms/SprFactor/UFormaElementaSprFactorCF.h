#ifndef UFormaElementaSprFactorCFH                  
#define UFormaElementaSprFactorCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprFactorCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprFactorCF();                                                           
   ~TFormaElementaSprFactorCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
