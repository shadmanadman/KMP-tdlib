package org.adman.kmp.tdlib

interface Platform {
    val name: String
}

expect fun getPlatform(): Platform