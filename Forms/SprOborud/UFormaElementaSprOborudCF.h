#ifndef UFormaElementaSprOborudCFH                  
#define UFormaElementaSprOborudCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprOborudCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprOborudCF();                                                           
   ~TFormaElementaSprOborudCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
