#ifndef UFormaElementaSprSkladCFH                  
#define UFormaElementaSprSkladCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprSkladCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprSkladCF();                                                           
   ~TFormaElementaSprSkladCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
