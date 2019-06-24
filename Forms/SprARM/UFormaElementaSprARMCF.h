#ifndef UFormaElementaSprARMCFH                  
#define UFormaElementaSprARMCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprARMCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprARMCF();                                                           
   ~TFormaElementaSprARMCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
