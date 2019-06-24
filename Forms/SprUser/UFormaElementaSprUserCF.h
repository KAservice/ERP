#ifndef UFormaElementaSprUserCFH                  
#define UFormaElementaSprUserCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprUserCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprUserCF();                                                           
   ~TFormaElementaSprUserCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
