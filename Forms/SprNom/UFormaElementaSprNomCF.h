#ifndef UFormaElementaSprNomCFH                  
#define UFormaElementaSprNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprNomCF();                                                           
   ~TFormaElementaSprNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
