#ifndef UFormaElementaSprProgramModuleCFH                  
#define UFormaElementaSprProgramModuleCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprProgramModuleCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprProgramModuleCF();                                                           
   ~TFormaElementaSprProgramModuleCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
