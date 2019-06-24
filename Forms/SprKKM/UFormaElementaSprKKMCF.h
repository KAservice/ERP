#ifndef UFormaElementaSprKKMCFH                  
#define UFormaElementaSprKKMCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprKKMCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprKKMCF();                                                           
   ~TFormaElementaSprKKMCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
