#ifndef UHOT_FormaElementaSprNFCFH                  
#define UHOT_FormaElementaSprNFCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaElementaSprNFCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaElementaSprNFCF();                                                           
   ~THOT_FormaElementaSprNFCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
