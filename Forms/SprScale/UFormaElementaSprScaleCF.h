#ifndef UFormaElementaSprScaleCFH                  
#define UFormaElementaSprScaleCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprScaleCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprScaleCF();                                                           
   ~TFormaElementaSprScaleCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
