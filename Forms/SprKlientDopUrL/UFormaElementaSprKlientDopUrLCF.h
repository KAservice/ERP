#ifndef UFormaElementaSprKlientDopUrLCFH                  
#define UFormaElementaSprKlientDopUrLCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprKlientDopUrLCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprKlientDopUrLCF();                                                           
   ~TFormaElementaSprKlientDopUrLCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
