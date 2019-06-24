#ifndef UFormaElementaSprNomImageCFH                  
#define UFormaElementaSprNomImageCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprNomImageCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprNomImageCF();                                                           
   ~TFormaElementaSprNomImageCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
