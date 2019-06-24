#ifndef UHOT_DMDocRaschetCFH                  
#define UHOT_DMDocRaschetCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_DMDocRaschetCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_DMDocRaschetCF();                                                           
   ~THOT_DMDocRaschetCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
