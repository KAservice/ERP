#ifndef UHOT_RaschetStoimProgCFH                  
#define UHOT_RaschetStoimProgCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_RaschetStoimProgCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_RaschetStoimProgCF();                                                           
   ~THOT_RaschetStoimProgCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
