#ifndef UFormaElementaSprOKEICFH                  
#define UFormaElementaSprOKEICFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprOKEICF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprOKEICF();                                                           
   ~TFormaElementaSprOKEICF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
