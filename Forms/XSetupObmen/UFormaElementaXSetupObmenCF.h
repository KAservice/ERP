#ifndef UFormaElementaXSetupObmenCFH                  
#define UFormaElementaXSetupObmenCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaXSetupObmenCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaXSetupObmenCF();                                                           
   ~TFormaElementaXSetupObmenCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
