#ifndef UFormaElementaSprMPrigCFH                  
#define UFormaElementaSprMPrigCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprMPrigCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprMPrigCF();                                                           
   ~TFormaElementaSprMPrigCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
