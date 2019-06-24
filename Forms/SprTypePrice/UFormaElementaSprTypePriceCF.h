#ifndef UFormaElementaSprTypePriceCFH                  
#define UFormaElementaSprTypePriceCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprTypePriceCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprTypePriceCF();                                                           
   ~TFormaElementaSprTypePriceCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
