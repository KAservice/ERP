#ifndef UDMDocRKOCFH                  
#define UDMDocRKOCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocRKOCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocRKOCF();                                                           
   ~TDMDocRKOCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
