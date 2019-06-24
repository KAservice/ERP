#ifndef UFormaElementaSprKlientCFH                  
#define UFormaElementaSprKlientCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprKlientCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprKlientCF();                                                           
   ~TFormaElementaSprKlientCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
