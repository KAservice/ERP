#ifndef UFormaElementaSprPodrCFH                  
#define UFormaElementaSprPodrCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprPodrCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprPodrCF();                                                           
   ~TFormaElementaSprPodrCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
