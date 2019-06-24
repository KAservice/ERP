#ifndef UFormaElementaSprVidImageCFH                  
#define UFormaElementaSprVidImageCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprVidImageCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprVidImageCF();                                                           
   ~TFormaElementaSprVidImageCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
