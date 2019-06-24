#ifndef UHOT_FormaDocRaschetCFH                  
#define UHOT_FormaDocRaschetCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaDocRaschetCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaDocRaschetCF();                                                           
   ~THOT_FormaDocRaschetCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
