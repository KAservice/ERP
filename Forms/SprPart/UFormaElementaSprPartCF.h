#ifndef UFormaElementaSprPartCFH                  
#define UFormaElementaSprPartCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprPartCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprPartCF();                                                           
   ~TFormaElementaSprPartCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
