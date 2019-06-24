#ifndef UFormaElementaSprProjectCFH                  
#define UFormaElementaSprProjectCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprProjectCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprProjectCF();                                                           
   ~TFormaElementaSprProjectCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
