#ifndef UFormaElementaSprEdCFH                  
#define UFormaElementaSprEdCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprEdCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprEdCF();                                                           
   ~TFormaElementaSprEdCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
