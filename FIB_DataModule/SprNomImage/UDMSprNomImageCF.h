#ifndef UDMSprNomImageCFH                  
#define UDMSprNomImageCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprNomImageCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprNomImageCF();                                                           
   ~TDMSprNomImageCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
