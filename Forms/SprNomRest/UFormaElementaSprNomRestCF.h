#ifndef UFormaElementaSprNomRestCFH                  
#define UFormaElementaSprNomRestCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprNomRestCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprNomRestCF();                                                           
   ~TFormaElementaSprNomRestCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
