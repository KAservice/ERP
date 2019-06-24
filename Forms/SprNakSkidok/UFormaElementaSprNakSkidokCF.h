#ifndef UFormaElementaSprNakSkidokCFH                  
#define UFormaElementaSprNakSkidokCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprNakSkidokCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprNakSkidokCF();                                                           
   ~TFormaElementaSprNakSkidokCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
