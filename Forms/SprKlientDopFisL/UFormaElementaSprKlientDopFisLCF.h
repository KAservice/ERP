#ifndef UFormaElementaSprKlientDopFisLCFH                  
#define UFormaElementaSprKlientDopFisLCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprKlientDopFisLCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprKlientDopFisLCF();                                                           
   ~TFormaElementaSprKlientDopFisLCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
