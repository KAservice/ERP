#ifndef UFormaElementaSprInfBaseCFH                  
#define UFormaElementaSprInfBaseCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprInfBaseCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprInfBaseCF();                                                           
   ~TFormaElementaSprInfBaseCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
