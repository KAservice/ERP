#ifndef UFormaElementaSprBrandCFH                  
#define UFormaElementaSprBrandCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprBrandCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprBrandCF();                                                           
   ~TFormaElementaSprBrandCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
