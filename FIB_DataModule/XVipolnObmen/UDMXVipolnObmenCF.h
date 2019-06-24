#ifndef UDMXVipolnObmenCFH                  
#define UDMXVipolnObmenCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMXVipolnObmenCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMXVipolnObmenCF();                                                           
   ~TDMXVipolnObmenCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
