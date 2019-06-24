#ifndef UREM_FormaElementaZayavkaImageCFH                  
#define UREM_FormaElementaZayavkaImageCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaZayavkaImageCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaZayavkaImageCF();                                                           
   ~TREM_FormaElementaZayavkaImageCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
